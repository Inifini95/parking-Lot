# URL Shortener - C++ Project

A modular C++ URL shortener application with a layered architecture.

## Project Structure

```
url_shortener/
├── CMakeLists.txt              # Build configuration
├── include/
│   ├── api/
│   │   └── url_shortener_api.h        # REST API wrapper layer
│   ├── service/
│   │   └── url_shortener_service.h    # Business logic / Service layer
│   └── implementation/
│       └── url_shortener_impl.h       # Core implementation layer
├── src/
│   ├── main.cpp                       # Entry point
│   ├── url_shortener_api.cpp          # API implementation
│   ├── url_shortener_service.cpp      # Service implementation
│   └── url_shortener_impl.cpp         # Implementation (logic to fill)
└── README.md                   # This file
```

## Architecture

### 1. **API Layer** (`include/api/url_shortener_api.h`)
   - REST API wrapper that handles HTTP requests/responses
   - Provides endpoints for creating and retrieving shortened URLs
   - Handles request/response serialization (JSON)
   - Contains error handling and status codes

### 2. **Service Layer** (`include/service/url_shortener_service.h`)
   - Business logic and validation
   - URL validation
   - Acts as an intermediary between API and implementation
   - Provides error handling and exception throwing

### 3. **Implementation Layer** (`include/implementation/url_shortener_impl.h`)
   - Core URL shortening algorithm (empty for you to implement)
   - `shortenURL()` - Convert long URLs to short codes
   - `expandURL()` - Convert short codes back to original URLs

## Building the Project

### Prerequisites
- CMake (version 3.10 or higher)
- C++17 compatible compiler (g++, clang, or MSVC)

### Build Steps

```bash
# Navigate to project directory
cd url_shortener

# Create build directory
mkdir build
cd build

# Generate build files
cmake ..

# Compile
cmake --build .

# Run the application
./url_shortener
```

## TODO: Implement the Shortening Logic

In [src/url_shortener_impl.cpp](src/url_shortener_impl.cpp), implement:

1. **`shortenURL(const std::string& original_url)`**
   - Implement your URL shortening algorithm
   - Store the mapping between short code and original URL
   - Return the generated short code

2. **`expandURL(const std::string& short_code)`**
   - Retrieve the original URL from the short code
   - Return the original URL or empty string if not found

### Suggested Approaches

- **Hash-based**: Hash the URL and encode it
- **Base62 Encoding**: Use auto-incrementing IDs with base62 encoding
- **In-memory Map**: Store URL mappings in a `std::map<std::string, std::string>`
- **Database-backed**: Integrate with SQLite for persistence

## Example Usage

```cpp
URLShortenerAPI api;

// Create a short URL
std::string response = api.handleCreateShortURL(R"({"url": "https://example.com"})");

// Get original URL
std::string original = api.handleGetOriginalURL("abc123");

// Health check
std::string health = api.healthCheck();
```

## Dependencies

- Standard C++ Library (STL)
- No external dependencies (uses only standard library for basic implementation)

## Future Enhancements

- Integrate a proper JSON library (e.g., nlohmann/json)
- Add HTTP server (e.g., cpp-httplib, Boost.Asio)
- Implement database persistence (SQLite, MySQL)
- Add unit tests
- Add configuration management
- Implement URL analytics and expiration
- Add rate limiting and authentication
