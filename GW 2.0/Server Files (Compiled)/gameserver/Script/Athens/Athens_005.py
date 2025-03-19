import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1023 , Script.Quest.QI1025 , Script.Quest.QI1026

def GetQuestReward():
  return Script.Quest.QR1022 , Script.Quest.QR1024 , Script.Quest.QR1025


def Talk( player ):
# print "talk to Athens_005"
  return "Athens_005"

