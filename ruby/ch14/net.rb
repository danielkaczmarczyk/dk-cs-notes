require 'net/http'

Net::HTTP.start("www.apress.com", use_ssl: true) do |http|
  req = Net::HTTP::Get.new('/sitemap.xml')
  body = http.request(req).body
  puts body.force_encoding("UTF-8")
end
