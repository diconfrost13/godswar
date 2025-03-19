import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_VENDOR)



def GetitemListType():
  return 3 , 4 , 5 , 6

def GetItemList():
  return Script.Item.ItemList301 , Script.Item.ItemList311 , Script.Item.ItemList321 , Script.Item.ItemList331

def Talk( player ):
# print "talk to Athens_031"
  return "Athens_031"

