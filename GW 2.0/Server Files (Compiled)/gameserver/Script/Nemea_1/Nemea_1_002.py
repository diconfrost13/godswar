import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI70 , Script.Quest.QI71 , Script.Quest.QI73 , Script.Quest.QI81

def GetQuestReward():
  return Script.Quest.QR69 , Script.Quest.QR70 , Script.Quest.QR72 , Script.Quest.QR80


def Talk( player ):
# print "talk to Nemea_1_002"
  return "Nemea_1_002"

