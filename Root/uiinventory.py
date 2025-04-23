#search in Class InventoryWindow
tooltipItem = None
#add under
	if app.SMART_SLOT_INFO:
		tooltipSlot = None
#search
wndEquip.SetOverOutItemEvent(ui.__mem_func__(self.OverOutItem))
#add under
		wndEquip.SetOverInSlotEvent(ui.__mem_func__(self.OverInSlot))
		wndEquip.SetOverOutSlotEvent(ui.__mem_func__(self.OverOutSlot))
#search
dlgPickMoney = uiPickItem.PickItemDialog()
#add above
		if app.SMART_SLOT_INFO:
			self.tooltipSlot = uiToolTip.ToolTip(140)
#search in def Hide
wndMgr.Hide(self.hWnd)
#add above
		if self.tooltipSlot and app.SMART_SLOT_INFO:
			self.tooltipSlot.HideToolTip()
#search
	def OverOutItem(self):
		self.wndItem.SetUsableItem(False)
		if None != self.tooltipItem:
			self.tooltipItem.HideToolTip()
#add under
	if app.SMART_SLOT_INFO:
		def OverInSlot(self, slotIndex):

			m_slotTooltip = {
				item.EQUIPMENT_WEAPON : uiScriptLocale.EQUIPMENT_WEAPON,
				item.EQUIPMENT_HEAD : uiScriptLocale.EQUIPMENT_HEAD,
				item.EQUIPMENT_BODY : uiScriptLocale.EQUIPMENT_ARMOR,
				item.EQUIPMENT_SHOES : uiScriptLocale.EQUIPMENT_SHOES,
				item.EQUIPMENT_WRIST : uiScriptLocale.EQUIPMENT_WRIST,
				item.EQUIPMENT_NECK : uiScriptLocale.EQUIPMENT_NECK,
				item.EQUIPMENT_EAR : uiScriptLocale.EQUIPMENT_EAR,
			}
			if slotIndex in m_slotTooltip and self.tooltipSlot and\
				(self.wndEquip.IsIn()):
				self.tooltipSlot.ClearToolTip()
				self.tooltipSlot.AutoAppendTextLine(m_slotTooltip[slotIndex])
				self.tooltipSlot.AlignHorizonalCenter()
				self.tooltipSlot.ShowToolTip()

		def OverOutSlot(self):
			if self.tooltipSlot:
				self.tooltipSlot.HideToolTip()
#by stoopid