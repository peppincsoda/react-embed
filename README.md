
## Introduction

This is a proof-of-concept to demonstrate how a ReactJS Web component can be shared between a ReactJS Web application and a native C++ application.
The interface that separates the shared component from the applications that embed the component is in pure JavaScript/TypeScript. So the presented method could be applied to any other Web frameworks as well.

## Components

### ClientApp

The shared UI component using React. Shows also an example on how to embed using vanilla JavaScript.

Requirements:
* Node v20

Build and run:
```bash
~/sandbox/react-embed/ClientApp $ npm run build
~/sandbox/react-embed/ClientApp $ open dist/index.html
```

### QtContainer

The Qt host application that uses ClientApp.

Requirements:
* ClientApp already built
* Qt5 installed at QT_PATH

Build and run:
```bash
~/sandbox/react-embed $ cp ClientApp/dist/client-bundle.js QtContainer/
~/sandbox/react-embed $ mkdir QtContainer-build
~/sandbox/react-embed $ cd QtContainer-build
~/sandbox/react-embed/QtContainer-build $ CMAKE_PREFIX_PATH="${QT_PATH}/lib/cmake/Qt5" cmake -G Ninja ../QtContainer
~/sandbox/react-embed/QtContainer-build $ ninja
~/sandbox/react-embed/QtContainer-build $ QT_LOGGING_RULES="js=true" ./QtContainer
```

### WebContainer

The Web host application.

Requirements:
* ClientApp already built
* Node v20

Build and run:
```bash
~/sandbox/react-embed $ mkdir -p WebContainer/dist/
~/sandbox/react-embed $ cp ClientApp/dist/client-bundle.js WebContainer/dist/
~/sandbox/react-embed $ cd WebContainer
~/sandbox/react-embed/WebContainer $ npm run build
~/sandbox/react-embed/WebContainer $ open dist/index.html
```

## Limitations
* An async function from JS to C++ cannot be called if there is already a pending call for that function.
The reason is that when the signal is emitted to resolve the call, the caller wouldn't know which call to resolve.
This could be solved by introducing a "transaction ID" for each call.
* For simplicity, the example event from C++ to JS only contains an event type parameter and no data.

## How to make it production ready
* Bundle names should contain a fingerprint and `index.html` shouldn't be cached to make updates work (without having to update the Qt app)
* CSS should be split out and compressed
* ?
