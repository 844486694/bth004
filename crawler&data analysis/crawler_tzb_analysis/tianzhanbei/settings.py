# -*- coding: utf-8 -*-

# Scrapy settings for tianzhanbei project
#
# For simplicity, this file contains only settings considered important or
# commonly used. You can find more settings consulting the documentation:
#
#     https://doc.scrapy.org/en/latest/topics/settings.html
#     https://doc.scrapy.org/en/latest/topics/downloader-middleware.html
#     https://doc.scrapy.org/en/latest/topics/spider-middleware.html
import os


BOT_NAME = 'tianzhanbei'
DOWNLOAD_DELAY = 0.25

SPIDER_MODULES = ['tianzhanbei.spiders']
NEWSPIDER_MODULE = 'tianzhanbei.spiders'

#
# FEED_FORMAT="CSV"
# FEED_URI='file:///D:/csv/tiaozhanbei/paper.csv'
# FEED_EXPORT_ENCODING='uft-8'
# Crawl responsibly by identifying yourself (and your website) on the user-agent

MYSQL_HOST = '127.0.0.1'
# MYSQL_HOST = '35.204.214.227'
MYSQL_DBNAME = 'theseus'         #数据库名字，请修改
MYSQL_USER = 'root'             #数据库账号，请修改
MYSQL_PASSWD = 'root'         #数据库密码，请修改

MYSQL_PORT = 3306



# Obey robots.txt rules
ROBOTSTXT_OBEY = False

# FeedExporter={
#     'json': 'scrapy.exporters.JsonItemExporter',
#     'jsonlines': 'scrapy.exporters.JsonLinesItemExporter',
#     'jl': 'scrapy.exporters.JsonLinesItemExporter',
#     'csv': 'scrapy.exporters.CsvItemExporter',
#     'xml': 'scrapy.exporters.XmlItemExporter',
#     'marshal': 'scrapy.exporters.MarshalItemExporter',
#     'pickle': 'scrapy.exporters.PickleItemExporter',
# }

# Configure maximum concurrent requests performed by Scrapy (default: 16)
#CONCURRENT_REQUESTS = 32

# Configure a delay for requests for the same website (default: 0)
# See https://doc.scrapy.org/en/latest/topics/settings.html#download-delay
# See also autothrottle settings and docs
#DOWNLOAD_DELAY = 3
# The download delay setting will honor only one of:
#CONCURRENT_REQUESTS_PER_DOMAIN = 16
#CONCURRENT_REQUESTS_PER_IP = 16

# Disable cookies (enabled by default)
# COOKIES_ENABLED = False

# Disable Telnet Console (enabled by default)
#TELNETCONSOLE_ENABLED = False

# Override the default request headers:
#DEFAULT_REQUEST_HEADERS = {
#   'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
#   'Accept-Language': 'en',
#}

# Enable or disable spider middlewares
# See https://doc.scrapy.org/en/latest/topics/spider-middleware.html
#SPIDER_MIDDLEWARES = {
#    'tianzhanbei.middlewares.TianzhanbeiSpiderMiddleware': 543,
#}

# Enable or disable downloader middlewares
# See https://doc.scrapy.org/en/latest/topics/downloader-middleware.html
DOWNLOADER_MIDDLEWARES = {
    'scrapy.contrib.downloadermiddleware.retry.RetryMiddleware': 500,
    "tianzhanbei.middlewares.customUserAgent.RandomUserAgent":543,
    "tianzhanbei.middlewares.proxy.RandomProxy":500,
    # "scrapy.contrib.downloadMiddleware.httpproxy.HttpProxyMiddle":400,
    # # 'scrapy.downloadermiddlewares.useragent.UserAgentMiddleware': None,
    # "scrapy.contrib.downloadermiddleware.useragent.UserAgentMiddleware":None
}

# Enable or disable extensions
# See https://doc.scrapy.org/en/latest/topics/extensions.html
#EXTENSIONS = {
#    'scrapy.extensions.telnet.TelnetConsole': None,
#}

# Configure item pipelines
# See https://doc.scrapy.org/en/latest/topics/item-pipeline.html
ITEM_PIPELINES = {
    'tianzhanbei.pipelines.TheseusPipeline':300
   # 'tianzhanbei.pipelines.TianzhanbeiPipeline': 300,
}

# Enable and configure the AutoThrottle extension (disabled by default)
# See https://doc.scrapy.org/en/latest/topics/autothrottle.html
#AUTOTHROTTLE_ENABLED = True
# The initial download delay
#AUTOTHROTTLE_START_DELAY = 5
# The maximum download delay to be set in case of high latencies
#AUTOTHROTTLE_MAX_DELAY = 60
# The average number of requests Scrapy should be sending in parallel to
# each remote server
#AUTOTHROTTLE_TARGET_CONCURRENCY = 1.0
# Enable showing throttling stats for every response received:
#AUTOTHROTTLE_DEBUG = False

# Enable and configure HTTP caching (disabled by default)
# See https://doc.scrapy.org/en/latest/topics/downloader-middleware.html#httpcache-middleware-settings
#HTTPCACHE_ENABLED = True
#HTTPCACHE_EXPIRATION_SECS = 0
#HTTPCACHE_DIR = 'httpcache'
#HTTPCACHE_IGNORE_HTTP_CODES = []
#HTTPCACHE_STORAGE = 'scrapy.extensions.httpcache.FilesystemCacheStorage'
