import React from 'react';
import { StrictMode } from 'react';
import { createRoot } from 'react-dom/client';
import App from './App';
import { ContainerApi } from './ContainerApi';
import { ContainerApiContext } from './ContainerApiContext';

globalThis.ClientUiFactory = {
  create(containerElement: HTMLElement, containerApi: ContainerApi): void {
    const root = createRoot(containerElement);
    root.render(
      <StrictMode>
        <ContainerApiContext.Provider value={containerApi}>
          <App/>
        </ContainerApiContext.Provider>
      </StrictMode>
    );
  }
};
