# -*- coding: utf-8 -*-
# @Time    : 12/8/2018 5:07 PM
# @Author  : 201619630303_杜天启
# @FileName: test.py
# @Software: PyCharm
from scrapy import Spider
import scrapy
from new.items import JiandanItem
class jiandanSpider(scrapy.Spider):
    name = 'jiandan'
    start_urls = ["http://jandan.net/ooxx"]

    def parse(self, response):

        item = JiandanItem()
        item['image_urls'] = response.xpath('//img//@src').extract() #提取图片链接
        print(item["image_urls"])
        yield item
    

