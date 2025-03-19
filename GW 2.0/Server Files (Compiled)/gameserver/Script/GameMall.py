import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetItemListType():
  return Script.NPCConfig.ITEM_TYPE_HOT,Script.NPCConfig.ITEM_TYPE_RECOVER

def GetItemList():
  return (Script.Item.ItemList1000,Script.Item.ItemList1001)

