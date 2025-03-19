import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI35 , Script.Quest.QI40 , Script.Quest.QI44

def GetQuestReward():
  return Script.Quest.QR34 , Script.Quest.QR39 , Script.Quest.QR43


def Talk( player ):
# print "talk to Sparta_Newbie_005"
  return "Sparta_Newbie_005"

