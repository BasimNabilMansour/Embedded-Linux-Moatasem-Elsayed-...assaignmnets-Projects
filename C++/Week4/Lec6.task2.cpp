#include <iostream>
#include <vector>
#include <string>
#include <sstream>

enum LogLevel {
    INFO,
    WARNING,
    ERROR
};

class Logger {
private:
    struct LogMessage {
        LogLevel level;
        std::string message;
    };

    std::vector<LogMessage> logBuffer;

    std::string logLevelToString(LogLevel level) const {
        switch (level) {
            case INFO: return "INFO";
            case WARNING: return "WARNING";
            case ERROR: return "ERROR";
            default: return "UNKNOWN";
        }
    }

public:
    // Method to log a message with a specified log level
    void log(LogLevel level, const std::string& message) {
        LogMessage logMessage = { level, message };
        logBuffer.push_back(logMessage);
    }

    // Method to dump all logs to the console
    void dumpLogs() const {
        for (const auto& logMessage : logBuffer) {
            std::cout << "[" << logLevelToString(logMessage.level) << "] " << logMessage.message << std::endl;
        }
    }

    // Method to clear the log buffer
    void clearBuffer() {
        logBuffer.clear();
    }

    // Method to dump logs to a string (for easier testing or file writing)
    std::string dumpLogsToString() const {
        std::ostringstream oss;
        for (const auto& logMessage : logBuffer) {
            oss << "[" << logLevelToString(logMessage.level) << "] " << logMessage.message << "\n";
        }
        return oss.str();
    }
};

int main() {
    Logger logger;

    // Logging some messages
    logger.log(INFO, "Application started");
    logger.log(WARNING, "Low disk space");
    logger.log(ERROR, "Failed to open file");

    // Dump logs to console
    std::cout << "Dumping logs to console:" << std::endl;
    logger.dumpLogs();
    

    // Dump logs to a string (useful for writing to a file or further processing)
    std::string logs = logger.dumpLogsToString();
    std::cout << "Logs as string:\n" << logs;

    // Clear the log buffer
    logger.clearBuffer();

    // Try dumping again (should be empty)
    std::cout << "Dumping logs after clearing buffer:" << std::endl;
    logger.dumpLogs();

    return 0;
}
