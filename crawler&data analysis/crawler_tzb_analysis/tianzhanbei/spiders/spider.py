from scrapy.spider import Spider
from tianzhanbei.items import  TianzhanbeiItem
import scrapy
class spider(Spider):
	name = "s"
	# allowed_domains = ["tiaozhanbei.net"]
	start_urls = ["http://www.tiaozhanbei.net/project/search/?category=&pro_type=&school_id=&province_id=&keyword=&school=undefined"]
	
	
	def __init__(self):
		self.search_domain="http://www.tiaozhanbei.net/project/search/"
		self.project_domain="http://www.tiaozhanbei.net/"
		
	def parse(self, response):
		next_page=response.xpath("//a[text()=\"下一页\"]/@href").extract_first()
		project_page=response.xpath("//div[@class='col-4-5 cont']//@href").re("^/project/[0-9]+/")
		project_page=list(set(project_page))
		for p in project_page:
			# print(self.project_domain+p)
			yield scrapy.Request(self.project_domain+p,callback=self.crawl_data,dont_filter=True)
		yield scrapy.Request(self.search_domain+next_page,callback=self.parse)
		
	def crawl_data(self,response):

		item=TianzhanbeiItem()
		item["category"]=response.xpath("/html/body/div[2]/div/div[2]/div[1]/div/dl/div[3]/dt/em/../../dd[@class='col-5-6 content']/a/text()").extract_first()
		item["name"]=response.xpath("/html/body/div[2]/div/div[2]/div[1]/div/dl/div[1]/dt/em/../../dd[@class='col-5-6 content']/text()").extract_first().strip(' \t\n\r')
		item["origin"]=response.xpath("/html/body/div[2]/div/div[2]/div[1]/div/dl/div[2]/dt/em/../../dd[@class='col-5-6 content']/a/text()").extract_first()

		yield  item