#pragma once
#include <filesystem>

namespace Imagify::Core::Constants
{
    static const std::filesystem::path dataDirectory = "../../data";
    static const std::filesystem::path faceClassifierPath = dataDirectory / "Core/haarcascade_frontalface_default.xml"; //!< Path to face classifier relative to bin.

} // namespace Imagify::Core::Constants