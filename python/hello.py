import http.server
import socketserver
PORT = 8000
class Handler(http.server.SimpleHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type", "text/html")
        self.end_headers()
        self.wfile.write(b"Hello, World!")
with socketserver.TCPServer(("", PORT), Handler) as httpd:
    print(f"Serving on port {PORT}")
    httpd.serve_forever()
#     print("Selection Sort:", selection_sort(test_array.copy()))
#     print("Insertion Sort:", insertion_sort(test_array.copy()))

