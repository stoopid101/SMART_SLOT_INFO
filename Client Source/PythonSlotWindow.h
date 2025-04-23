//Search
void OnOverOutItem();
//add under
#ifdef SMART_SLOT_INFO

			BOOL OnOverInSlot(DWORD dwSlotNumber);
			void OnOverOutSlot();
#endif
//Search
TSlotList m_SlotList;
//add under
#ifdef SMART_SLOT_INFO
			DWORD m_dwOverInSlotNumber;
#endif
//by stoopid