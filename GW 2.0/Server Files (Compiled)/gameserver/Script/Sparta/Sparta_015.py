import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI116 , Script.Quest.QI117 , Script.Quest.QI118 , Script.Quest.QI119 , Script.Quest.QI120 , Script.Quest.QI121 , Script.Quest.QI122

def GetQuestReward():
  return Script.Quest.QR116 , Script.Quest.QR117 , Script.Quest.QR118 , Script.Quest.QR119 , Script.Quest.QR120 , Script.Quest.QR121 , Script.Quest.QR122


def Talk( player ):
# print "talk to Sparta_015"
  return "Sparta_015"

