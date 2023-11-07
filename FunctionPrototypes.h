#ifndef FUNCTIONPROTOTYPES_H_INCLUDED
#define FUNCTIONPROTOTYPES_H_INCLUDED
#include "STD.h"

// Function Prototypes
bool SDB_IsFull(void);
bool SDB_AddEntry(void);
bool SDB_IsIdExist(uint32 id);
void SDB_DeletEntry(uint32 id);
uint8 SDB_GetUsedSize(void);
bool SDB_ReadEntry(uint32 id);
void SDB_GetList(uint8* count, uint32* list);


#endif // FUNCTIONPROTOTYPES_H_INCLUDED
