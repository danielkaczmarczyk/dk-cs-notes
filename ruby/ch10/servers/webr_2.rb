require 'webrick'

class MyNormalClass
  def MyNormalClass.add(a, b)
    a.to_i + b.to_i
  end

  def MyNormalClass.subtract(a, b)
    a.to_i - b.to_i
  end
end

class MyServlet < WEBrick::HTTPServlet::AbstractServlet
  def do_GET(request, response)
    if request.query['a'] && request.query['b']
      a = request.query['a']
      b = request.query['b']
      response.status = 200
      response.content_type = 'text/plain'
      result = nil

      case request.path
      when '/add'
        result = MyNormalClass.add(a,b)
      when '/subtract'
        result = MyNormalClass.subtract(a,b)
      else
        result = "no such method"
      end

      response.body = result.to_s + "\n"
    else
      response.status = 400
      response.body = "You did not provide the correct parameters"
    end
  end
end

server = WEBrick::HTTPServer.new(:Port => 1234)
server.mount "/", MyServlet
trap("INT") { server.shutdown }
server.start

