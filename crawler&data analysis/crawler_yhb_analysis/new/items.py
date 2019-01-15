# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# https://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class my_Item(scrapy.Item):
    # define the fields for your item here like:
    # name = scrapy.Field()
    download=scrapy.Field()
    url=scrapy.Field()
class JiandanItem(scrapy.Item):
    image_urls = scrapy.Field()#图片的链接
    images = scrapy.Field()