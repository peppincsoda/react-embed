/* This file contains the contract between the container and the client components. */

/**
 * The services provided by the container to ClientApp
 */
export type EventHandler = (event: string) => void;

export interface ContainerApi {
  load(): Promise<any>;

  addEventListener(fn: EventHandler): void;
  removeEventListener(fn: EventHandler): void;
}

interface ClientUiFactory {
  /**
   * Render the UI as a child of `containerElement`
   */
  create(containerElement: HTMLElement, containerApi: ContainerApi): void;
}

declare global {
  /**
   * The UI factory is available as `globalThis.ClientUiFactory`
   */
  var ClientUiFactory: ClientUiFactory;
}
