import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_VENDOR)



def GetitemListType():
  return 7 , 8 , 9 , 10

def GetItemList():
  return Script.Item.ItemList401 , Script.Item.ItemList411 , Script.Item.ItemList421 , Script.Item.ItemList431

def Talk( player ):
# print "talk to Sparta_037"
  return "Sparta_037"

