# -*- coding: utf-8 -*-
# @Time    : 12/10/2018 8:27 PM
# @Author  : 201619630303_杜天启
# @FileName: theseus_spider.py
# @Software: PyCharm

from scrapy.spiders import Spider
from tianzhanbei.items import theseusItem
import scrapy

class spider(Spider):
	name="theseus"
	subject='computer science'
	page=1
	start_urls=[
		"http://www.theseus.fi/discover?filtertype=programme&filter_relational_operator=equals&filter=Tietojenk%C3%A4sittelyn+koulutusohjelma"]
	domain="http://www.theseus.fi/"
	def parse(self, response):
		paper_url=response.xpath('//*[@id="aspect_discovery_SimpleSearch_div_search-results"]//@href').extract()

		next_page=response.xpath('//*[@class="next-page-link"]/@href').extract_first()
		self.page+=1

		for p in paper_url:
			yield  scrapy.Request(self.domain+p,callback=self.enter_page)
		if next_page:
			print(self.page)
			yield scrapy.Request(self.domain+next_page,callback=self.parse)

	
		# cate_url=response.xpath('//*[@id="aspect_discovery_Navigation_list_discovery"]/a/@href').extract()
		# # cate=response.xpath('//*[@id="aspect_discovery_Navigation_list_discovery"]/a/text()').extract()
		# # print(cate)
		# # yield scrapy.Request(self.domain+cate_url[0],callback=self.enter_page)
		# for url in cate_url:
		# 	# print(self.domain+url)
		# 	yield scrapy.Request(self.domain+url,callback=self.enter_page)


	def enter_page(self,response):
		detail=response.xpath('//*[@id="aspect_artifactbrowser_ItemViewer_div_item-view"]/div/div[2]/div[1]/div[6]/a/@href').extract_first()
		yield scrapy.Request(self.domain+detail,callback=self.parse_paper)

	def parse_paper(self,response):
		item=theseusItem()
		
		item["paper"]=response.xpath('//h2/text()').extract_first()
		if response.xpath('//td[text()="dc.orientation"]/../td/text()').extract():
			item["cate"]=response.xpath('//td[text()="dc.orientation"]/../td/text()').extract()[1]
		else:
			item["cate"]="None"
			
		item["subject"]=self.subject
		
		item["url"]=self.domain+response.xpath('//*[@id="aspect_artifactbrowser_ItemViewer_div_item-view"]/div[2]/div/div[3]/a/@href').extract_first()
		
		item["author"]=response.xpath('//*[text()="dc.contributor.author"]/../td/text()').extract()[1]
		item["year"]=response.xpath('//*[text()="dc.date.issued"]/../td/text()').extract()[1]
		item["institution"]=response.xpath('//*[text()="dc.organization"]/../td/text()').extract()[1]
		item["degree"]=response.xpath('//*[text()="dc.type.ontasot"]/../td/text()').extract()[-2]
		kw=list(set(response.xpath('//*[text()="dc.keyword"]/../td/text()').extract()))
		try:
			kw.remove("-")
			kw.remove("dc.keyword")
		except Exception:
			pass

		item["keyword"]=','.join(kw)
		# print(item)
		yield item