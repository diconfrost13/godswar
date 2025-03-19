import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1072 , Script.Quest.QI1080 , Script.Quest.QI1091

def GetQuestReward():
  return Script.Quest.QR1071 , Script.Quest.QR1079 , Script.Quest.QR1090


def Talk( player ):
# print "talk to Parnitha_1_003"
  return "Parnitha_1_003"

