import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_VENDOR)



def GetitemListType():
  return 1 , 2

def GetItemList():
  return Script.Item.ItemList103 , Script.Item.ItemList113

def Talk( player ):
# print "talk to Athens_Newbie_016"
  return "Athens_Newbie_016"

