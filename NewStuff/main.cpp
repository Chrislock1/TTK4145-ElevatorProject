#include <iostream>

using namespace std;

int main(void) {
    // INITS //

    // ENABLE PROCESS PAIR FAULT TOLERANCE LAYER//

    // ENABLE LOCAL BACKWARD RECOVERY LAYER //

    // ENABLE CONNECTION THREAD, if no pre-existing network, create one and become master //

    // ENABLE ELEVATOR SENSOR THREAD // 

    // ENABLE ELEVATOR DRIVER THREAD //

    while (true) {
        /* PROCESS PAIR: BACKUP
         *      Timeout? If yes: become master
         *      Receive I'm alive message containing current state information, compare master ID and test CRC (master ID to take over)
         */

        /* PROCESS PAIR: MASTER
         *      If backup has become master: Terminate
         *      Send I'm alive message containing state information, master ID and CRC
         */


        /* BACK WARD RECOVERY LAYER:
         *      Still connected?
         *      Sensors thread responding?
         *      Elevator thread responding?
         *      More..?
         */

        /* "ITERATE MEETING"
         *      What is the current state?
         *          - All elevators position (and have we lost any?)
         *          - Current and new requests and who's handling them (have we lost an elevator who handled a request?)
         *          - Synchronize and validate new state (Compare CRC with master)
         */

        /* LOCAL STUFF
         *      Use request-handle resolving algorithm to determine which elevator should handle unhandled request (reduce cost function)
         *      Send new local requests to local elevator driver
         *      Pull new requests from local sensor driver
         */
    }
}