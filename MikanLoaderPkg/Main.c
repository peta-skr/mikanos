#include  <Uefi.h>
#include  <Library/UefiLib.h>

EFI_STATUS EFIAPI UefiMain(
    EFI_HANDLE image_handle,
    EFI_SYSTEM_TABLE *system_table) {
  Print(L"Hello, Mikan World!\n");
  while (1);
  return EFI_SUCCESS;
}

EFI_STATUS GetMemoryMap(
  IN OUT UINTN *MemoryMapSize,
  IN OUT EFI_MEMORY_DESCRIPTOR *MemoryMap,
  OUT UINTN *MapKey,
  OUT UINTN *DescriptorSize,
  OUT UINT32 *DescriptorVersion
);

EFI_STATUS GetMemoryMap(struct MemoryMap* map) {
  if (map->buffer == NULL) {
    return EFI_BUFFER_TOO_SMALL;
  }

  map->map_size = map_buffer_size;
  return gBS->GetMemoryMap(
    &map->map_size,
    (EFI_MEMORY_DESCRIPTOR*)map->buffer,
    &map->descriptor_size,
    &map->descriptor_version
  );
}