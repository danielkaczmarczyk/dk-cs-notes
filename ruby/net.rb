require 'net/http'

uri = URI('https://ruby-doc.org')
req = Net::HTTP.new(uri.host, uri.port)
req.use_ssl = true
res = req.get('/')
puts res.body.force_encoding("ISO-8859-1")
