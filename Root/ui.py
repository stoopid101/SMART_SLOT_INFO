#search in class SlotWindow(Window):
	def SetOverOutItemEvent(self, event):
		self.eventOverOutItem = event
#add under
	if app.SMART_SLOT_INFO:
		def SetOverInSlotEvent(self, event, *args):
			self.eventOverInSlot = event
			self.eventOverInSlotArgs = args

		def SetOverOutSlotEvent(self, event):
			self.eventOverOutSlot = event
#search 
	## Event
	def OnSelectEmptySlot(self, slotNumber):
		if self.eventSelectEmptySlot:
			self.eventSelectEmptySlot(slotNumber)
#add above
	if app.SMART_SLOT_INFO:
		def OnOverIn(self, slotNumber):
			if self.eventOverInSlot:
				if self.eventOverInSlotArgs:
					apply(self.eventOverInSlot, self.eventOverInSlotArgs)
				else:
					self.eventOverInSlot(slotNumber)

		def OnOverOut(self):
			if self.eventOverOutSlot:
				self.eventOverOutSlot()
#by stoopid