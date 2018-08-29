
import requests
from urllib import parse

class HttpMethod(object):

    def get(url):
        resp = requests.get(url=url)
        return resp.text

    def post(url, data):
        headers = {'content-type': 'application/x-www-form-urlencoded; charset=UTF-8'}
        resp = requests.post(url=url, data=data, headers=headers)

        return resp.text

    def encode(data):
        return parse.quote(data)

    def decode(data):
        return parse.unquote(data)