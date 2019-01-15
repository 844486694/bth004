# -*- coding: utf-8 -*-
# @Time    : 12/12/2018 7:31 PM
# @Author  : 201619630303_杜天启
# @FileName: customUserAgent.py
# @Software: PyCharm
from scrapy.contrib.downloadermiddleware.useragent import UserAgentMiddleware
from tianzhanbei.middlewares.resource import USER_AGENT_LIST


import random

class RandomUserAgent(UserAgentMiddleware):
    def process_request(self, request, spider):
        ua = random.choice(USER_AGENT_LIST)
        request.headers.setdefault('User-Agent', ua)