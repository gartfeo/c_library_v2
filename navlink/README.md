# NavLink MAVLink Protocol

Custom MAVLink messages for swarm coordination.

## Generating Headers

To regenerate the C headers from the XML definition:

```python
python -c "
from pymavlink.generator import mavgen
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--lang', default='C')
parser.add_argument('--wire-protocol', default='2.0')
parser.add_argument('-o', '--output', required=True)
parser.add_argument('definitions', nargs='+')

args = parser.parse_args(['--lang=C', '--wire-protocol=2.0', '-o', 'navlink', 'message_definitions/navlink.xml'])

opts = mavgen.Opts(args.output, wire_protocol=args.wire_protocol, language=args.lang)
mavgen.mavgen(opts, args.definitions)
"
```

Or use mavgen directly if available:

```bash
mavgen.py --lang=C --wire-protocol=2.0 -o navlink message_definitions/navlink.xml
```

## Requirements

- Python 3.x
- pymavlink (`pip install pymavlink`)

## Messages

All messages include dedup/TTL metadata fields:
- `boot_id`: Random ID per process start (identifies sender instance)
- `msg_seq`: Monotonic counter per sender (unique per message)
- `time_ms`: Sender timestamp in milliseconds
- `ttl_ms`: Time-to-live in milliseconds

### Peer Presence
- **CHECK_IN** (25002): Announce presence when joining swarm
- **CHECK_OUT** (25003): Announce departure from swarm with location
- **SWARM_HEARTBEAT** (25004): Peer liveness and clock sync (1Hz, TTL 5000ms)

### Task Coordination
- **AVAILABLE_TASK_REQUEST** (25104): Broadcast available tasks
- **AVAILABLE_TASK_RESPONSE** (25105): Response with ETA for tasks
- **TASK_ASSIGN_REQUEST** (25106): Assign task to peer
- **TASK_ASSIGN_RESPONSE** (25107): Accept/reject assignment
- **TASK_CONFIRM_REQUEST** (25108): Request ground station confirmation
- **TASK_CONFIRM_RESPONSE** (25109): Ground station response

### Slot Management
- **SLOT_HEARTBEAT** (25200): TDMA-style heartbeat (3Hz, TTL 1000ms)
- **SLOT_CLAIM** (25201): Claim a time slot (TTL 2000ms)
- **VOTE_PHASE** (25202): Consensus voting (TTL 6000ms)

### Search
- **SEARCH_STATUS** (25300): Search area status update (TTL 15000ms)
