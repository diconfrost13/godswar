import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_VENDOR)



def GetitemListType():
  return 3 , 4 , 5 , 6

def GetItemList():
  return Script.Item.ItemList203 , Script.Item.ItemList213 , Script.Item.ItemList223 , Script.Item.ItemList233

def Talk( player ):
# print "talk to Nemea_1_016"
  return "Nemea_1_016"

