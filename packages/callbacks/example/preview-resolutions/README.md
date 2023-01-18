# tizen_interop_callbacks_example

Demonstrates how to use the tizen_interop_callbacks plugin.

## Getting Started

The application shows a list of supported camera preview resolutions.

The `camera_foreach_supported_preview_resolution()` is called from a spawned
isolate because it blocks the calling thread.
