import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_VENDOR)



def GetitemListType():
  return 1 , 

def GetItemList():
  return Script.Item.ItemList102 , Script.Item.ItemList0

def Talk( player ):
# print "talk to Derveni_All_001"
  return "Derveni_All_001"

