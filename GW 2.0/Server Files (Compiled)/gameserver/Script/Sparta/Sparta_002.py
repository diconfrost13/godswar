import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI16 , Script.Quest.QI17 , Script.Quest.QI61 , Script.Quest.QI67

def GetQuestReward():
  return Script.Quest.QR15 , Script.Quest.QR16 , Script.Quest.QR60 , Script.Quest.QR66


def Talk( player ):
# print "talk to Sparta_002"
  return "Sparta_002"

