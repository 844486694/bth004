# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://doc.scrapy.org/en/latest/topics/item-pipeline.html
import scrapy
from scrapy.pipelines.files import FilesPipeline
from scrapy.pipelines.images import ImagesPipeline
from scrapy.exceptions import DropItem


class my_pipeline(FilesPipeline):
	def get_media_requests(self, item, info):
		for i in item["download"]:
			yield scrapy.Request(i)

	def item_completed(self, results, item, info):
		image_paths = [x['path'] for ok, x in results if ok]
		if not image_paths:
			raise DropItem("Item contains no images")
		return item
class JiandanPipeline(ImagesPipeline):#继承ImagesPipeline这个类

    def get_media_requests(self, item, info):
        for image_url in item['image_urls']:
            image_url = "http:" + image_url
            yield scrapy.Request(image_url)

    def item_completed(self, results, item, info):
        image_paths = [x['path'] for ok, x in results if ok]
        if not image_paths:
            raise DropItem("Item contains no images")
        return item


