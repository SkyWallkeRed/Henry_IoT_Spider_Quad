void initSoundModuleListener() {
  if (soundModuleSensoreValue >= 1) {
    sit();
    printToOled("sit");
    headDemo();
  }
}
