import React from 'react';

class WebContainerApi {
  constructor() {
    this.listeners = [];
  }

  async load() {
    return Promise.resolve({test: 42});
  }

  addEventListener(fn) {
    this.listeners.push(fn);
  }
  removeEventListener(fn) {
    this.listeners.splice(this.listeners.indexOf(fn), 1);
  }

  sendEventToClient(event_type) {
    for (let fn of this.listeners) {
      fn(event_type);
    }
  }
}

export function App() {
  const refElement = React.useRef(null);
  const refApi = React.useRef(null);

  React.useEffect(() => {
    refApi.current = new WebContainerApi();
    globalThis.ClientUiFactory.create(refElement.current, refApi.current);
  }, []);

  function sendEventToClient() {
    refApi.current.sendEventToClient('test_event');
  }

  return (
    <>
      <div>Container</div>
      <button onClick={sendEventToClient}>Send event to the client</button>
      <div className="container">
        <div className="child">
          <div ref={refElement}></div>
        </div>
      </div>
    </>
  );
}
