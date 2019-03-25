---
name: Bug report
about: Thanks for submitting a bug you've found!
title: "[BUG]"
labels: ''
assignees: ''

---

------------------------------- delete below -------------------------------

INSTRUCTIONS
==========

Follow this template because we want to solve any problems you find as quick as possible, and following it helps us do just that.

------------------------------- delete above -------------------------------

**Sample**

iothub_ll_connect_to_jupiter.c

**Development Machine, OS, Compiler (and Other Relevant Toolchain Info)**

Raspberry Pi, Raspbian Stretch Lite (Release 2018-11-13)
Cross Compiled on Ubuntu 18.04 using GCC 6.3.0

**SDK Version**

Latest apt-get

**Protocol**

MQTT

**Describe the Bug**

Blah blah blah MQTT. Foo blah blah carpe diem Azure blah blah IoT. Blah blah foo blah timeout blah blah blah connect.

**[MCVE](https://stackoverflow.com/help/mcve)**

```
#include "iothub.h"

int main(void)
{
    if (lightbulb == ON) {
        iothub_say_hello();
        return 0;
    } else {
        iothub_say_goodbye();
        return 1;
    }
}
```

**Console Logs**

Sending message 1 to IoTHub
-> 15:07:42 PUBLISH | IS_DUP: false | RETAIN: 0 | QOS: DELIVER_AT_LEAST_ONCE | TOPIC_NAME: devices/tracingDevice/messages/events/property_key=property_value | PACKET_ID: 93 | PAYLOAD_LEN: 12
<- 15:07:42 PUBACK | PACKET_ID: 92
Confirmation callback received for message 86 with result IOTHUB_CLIENT_CONFIRMATION_OK
