#include <string>

#include <fmt/core.h>

#include <OpenImageIO/imagecache.h>
#include <OpenImageIO/imageio.h>

int main(int argc, char* argv[])
{
    std::cout << "OpenImageIO " << OIIO_VERSION_STRING << "\n";

    std::string formats = OIIO::get_string_attribute("format_list");
    std::cout << "Supported formats:\n" << formats << "\n\n";

    // Optionally try to read a file and display the resolution
    if (argc == 2)
    {
        std::string filepath(argv[1]);

        auto image_reader = OIIO::ImageInput::open(filepath);
        const auto& spec = image_reader->spec();
        fmt::print("Image file {} loaded: {}x{} pixels with {} channels\n", filepath,
                spec.width, spec.height, spec.nchannels);
    }

    return 0;
}
