import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)


def GetQuestReward():
  return Script.Quest.QR210 , Script.Quest.QR211 , Script.Quest.QR212 , Script.Quest.QR227 , Script.Quest.QR228 , Script.Quest.QR229 , Script.Quest.QR230


def Talk( player ):
# print "talk to Sparta_045"
  return "Sparta_045"

