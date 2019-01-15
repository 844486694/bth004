from  scrapy import Spider
import scrapy
from new.items import my_Item
import re
class my_spider(Spider):
	name="my_spider"
	
	def __init__(self):
		self.domain="http://www.jgxy.zjut.edu.cn/"
	def start_requests(self):
		urls = ["http://www.jgxy.zjut.edu.cn/jgxy/technology/typeid-20.html", ]
		for url in urls:
			yield scrapy.Request(url=url, callback=self.parse)

	def parse(self,response):
		print(response)
		urls=response.xpath("//@href ").re("/jgxy/technology_detail/.+")
		next_page=response.xpath("//a[text()=\"下一页\"]/@href ").extract_first()
		print("next_page %s",next_page)
		for url in urls:
			yield scrapy.Request(self.domain+url,callback=self.parse_download)
		if next_page:
			yield  scrapy.Request(self.domain+next_page,callback=self.parse)
			
	def parse_download(self,response):
		# item=my_Item()
		# item["download"]=response.xpath("//a/@href").re("[.]xls$")
		# yield item
		download=response.xpath("//@href").re(r"^.+\.xls$")
		for d in range(len(download)):
			if re.match(r"^http:.+",download[d]):
				pass
			else:
				download[d]=self.domain+download[d]
		item=my_Item()
		item["download"]=download
		yield item