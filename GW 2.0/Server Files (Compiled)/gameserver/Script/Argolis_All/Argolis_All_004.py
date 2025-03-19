import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI86 , Script.Quest.QI87 , Script.Quest.QI88 , Script.Quest.QI165 , Script.Quest.QI166 , Script.Quest.QI169 , Script.Quest.QI217

def GetQuestReward():
  return Script.Quest.QR85 , Script.Quest.QR86 , Script.Quest.QR87 , Script.Quest.QR165 , Script.Quest.QR166 , Script.Quest.QR169 , Script.Quest.QR222


def Talk( player ):
# print "talk to Argolis_All_004"
  return "Argolis_All_004"

