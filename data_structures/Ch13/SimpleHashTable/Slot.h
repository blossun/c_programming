#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

typedef int Key;
typedef Person * Value;

enum SlotStatus {EMPTY, DELETED, INUSE};

typedef struct _slot
{
	Key key; // 주민번호
	Value val; // Person 구조체 변수의 주소 값
	enum SlotStatus status;
}Slot;

// Slot : 테이블을 이루는, 데이터를 저장할 수 있는 각각의 공간 - 키,값
#endif
