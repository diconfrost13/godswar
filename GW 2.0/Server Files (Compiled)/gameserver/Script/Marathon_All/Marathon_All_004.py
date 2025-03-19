import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1051 , Script.Quest.QI1052 , Script.Quest.QI1056 , Script.Quest.QI1054 , Script.Quest.QI1218

def GetQuestReward():
  return Script.Quest.QR1050 , Script.Quest.QR1051 , Script.Quest.QR1055 , Script.Quest.QR1053


def Talk( player ):
# print "talk to Marathon_All_004"
  return "Marathon_All_004"

