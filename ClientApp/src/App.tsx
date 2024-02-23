import React, { useEffect, useRef, useState } from 'react';
import { useContext } from 'react';
import { Alert, Button, Stack } from '@mui/material';

import { ContainerApi } from './ContainerApi';
import { ContainerApiContext } from './ContainerApiContext';

export default function App() {
  const containerApi: ContainerApi = useContext(ContainerApiContext);
  const [loadedValue, setLoadedValue] = useState('');
  const [showAlert, setShowAlert] = useState(false);
  const timerId = useRef(null);

  function eventHandler(event: string) {
    setShowAlert(true);

    if (timerId.current) {
      clearTimeout(timerId.current);
    }
    timerId.current = setTimeout(() => { setShowAlert(false); }, 3000);
  }

  useEffect(() => {
    return () => {
      if (timerId.current) {
        clearTimeout(timerId.current);
      }
    };
  }, []);

  useEffect(() => {
    containerApi.addEventListener(eventHandler);
    return () => containerApi.removeEventListener(eventHandler);
  }, []);

  async function handleLoadClick() {
    const r = await containerApi.load();
    setLoadedValue(JSON.stringify(r));
  }

  return (
    <Stack spacing={2}>
      <p><strong>Client</strong></p>
      <p>Click the button to load the value from the container</p>
      <Button variant="contained" onClick={handleLoadClick}>Load</Button>
      <p>Loaded value: {loadedValue}</p>
      {showAlert &&
        <Alert severity="success">
          Event received from the container.
        </Alert>
      }
    </Stack>
  );
}
