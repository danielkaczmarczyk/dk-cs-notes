use Rack::Static, :urls => { "/" => "index.html" }, :root => "public"
run Rack::Directory.new("public")