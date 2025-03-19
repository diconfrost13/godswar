import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI5 , Script.Quest.QI6 , Script.Quest.QI36 , Script.Quest.QI38

def GetQuestReward():
  return Script.Quest.QR4 , Script.Quest.QR5 , Script.Quest.QR35 , Script.Quest.QR37


def Talk( player ):
# print "talk to Sparta_Newbie_002"
  return "Sparta_Newbie_002"

