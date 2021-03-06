# 0.3.0 - X Xth 2021 (ongoing)

## Bug fixes
- Fix issue of `#include <cl2.hpp>` vs `#include <opencl.hpp>` ([#37](https://github.com/clEsperanto/CLIc_prototype/issues/37))
- Fix crossplatform OpenCL include `#include <opencl.hpp>` vs `#include <CL/opencl.hpp>` vs `#include <OpenCL/opencl.hpp>`

## New features  

- OpenCL kernels are now stored included into header instead of behind read at execution time. ([#32](https://github.com/clEsperanto/CLIc_prototype/issues/32))
- Rework of CMake project configuration
  - CMake search for OpenCL system installation: `find_package(OpenCL REQUIRED)`
  - Use [OpenCL API C++ Binding](https://github.com/KhronosGroup/OpenCL-CLHPP) submodule if not installed on system.
  - Run Python script `stringify.py` at build time for converting `.cl` into `.h`
  - New configuration options for building test, benchmark, code coverage, and documentations
  - Define OpenCL standard version to use (Default: 1.2)
- Rewrite of installation documentation
- Organising filters into Tiers folders
- `cleGPU` now display information on all platform and device or on specific device.
- User can now select specific device based on name.



# 0.2.0 - February 1st 2020 (not released)

## Bug fixes
- Fix memory leak from GPU due to a wrong object deletion

## New features
- CI github actions for testing build
- Generic benchmark for execution speed comparison between two filters
- `cleGPU` now allows save and reload compiled kernel. Avoid recompiling source if not needed. 
- Implementation of complexe filters:
  - block_enumerate
  - maximum_of_all_pixels
  - minimum_of_all_pixels
  - sum_of_all_pixels
  - difference_of_Gaussian
  - close_index_gaps_in_label_map
  - connected_component_labelling_box

## Miscellaneous

- Rework on Manager classes, now relying on [OpenCL API C++ Binding](https://github.com/KhronosGroup/OpenCL-CLHPP).
  
# 0.1.0 - November 30th 2020
First release for I2K2020 Tutorial.

## New features
- Setup of CMake configuration
- Creation of the core classes
  * Manager classes: `cleGPU`, `clePlatformManager`, `cleDeviceManager`, `cleContextManager`, `cleCommandQueueManager` 
  * Data and filters classes: `cleBuffer`, `cleKernel`
  * DataType classes: `cleLightObject`, `cleInt`, `cleFloat`
  * Data operations: `Pull`, `Push`, `Create`
- Creation of a Gateway class for users `CLE`
- Implementation of several basic filters
  * absolute
  * add_image_and_scalar
  * add_images_weighted
  * copy
  * detect_maxima
  * dilate_sphere
  * equal
  * equal_constant
  * erode_sphere
  * flag_existing_labels
  * gaussian_blur_separable
  * greater
  * greater_constant
  * greater_or_equal
  * greater_or_equal_constant
  * maximum_separable
  * maximum_x_projection
  * maximum_y_projection
  * maximum_z_projection
  * mean_separable
  * mean_sphere
  * minimum_separable
  * minimum_x_projection
  * minimum_y_projection
  * minimum_z_projection
  * nonzero_minimum_box
  * not_equal
  * not_equal_constant
  * replace_intensities
  * replace_intensity
  * set
  * set_column
  * set_nonzero_pixels_to_pixelindex
  * smaller
  * smaller_constant
  * smaller_or_equal
  * smaller_or_equal_constant
  * sobel
  * sum_reduction
  * sum_x_projection
  * sum_y_projection
  * sum_z_projection
