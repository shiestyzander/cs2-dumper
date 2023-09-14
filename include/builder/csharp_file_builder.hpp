#pragma once

namespace builder {
    class CSharpFileBuilder : public IFileBuilder {
    public:
        std::string get_extension() noexcept override {
            return "cs";
        }

        void write_top_level(std::ofstream& output) noexcept override {
            // Nothing needed here.
        }

        void write_namespace(std::ofstream& output, const std::string& namespace_name) noexcept override {
            output << "public static class " << namespace_name << " {\n";
        }

        void write_variable(std::ofstream& output, const std::string& variable_name, const std::uint64_t variable_value) noexcept override {
            output << "    public const ulong " << variable_name << " = 0x" << std::hex << variable_value << ";\n";
        }

        void write_closure(std::ofstream& output, const bool eof) noexcept override {
            output << (!eof ? "}\n\n": "}");
        }
    };
}