import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_VENDOR)



def GetitemListType():
  return 15 , 16 , 17

def GetItemList():
  return Script.Item.ItemList601 , Script.Item.ItemList611 , Script.Item.ItemList621

def Talk( player ):
# print "talk to Sparta_030"
  return "Sparta_030"

