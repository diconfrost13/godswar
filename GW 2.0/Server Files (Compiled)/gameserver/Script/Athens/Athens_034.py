import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_VENDOR)



def GetitemListType():
  return 11 , 12 , 13 , 14

def GetItemList():
  return Script.Item.ItemList501 , Script.Item.ItemList511 , Script.Item.ItemList521 , Script.Item.ItemList531

def Talk( player ):
# print "talk to Athens_034"
  return "Athens_034"

