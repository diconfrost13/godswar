import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_VENDOR)



def GetitemListType():
  return 15 , 16 , 17

def GetItemList():
  return Script.Item.ItemList603 , Script.Item.ItemList613 , Script.Item.ItemList623

def Talk( player ):
# print "talk to Nemea_1_019"
  return "Nemea_1_019"

