class EventEmitter {
    eventCallbacks = {};
    
    subscribe(event, ele) {
        if (this.eventCallbacks[event])
            this.eventCallbacks[event].push(ele);
        else
            this.eventCallbacks[event] = [ele];

        return {
            unsubscribe: () => {
                if (this.eventCallbacks[event] && this.eventCallbacks[event].length > 1)
                    this.eventCallbacks[event].pop();
                else
                    delete this.eventCallbacks[event];
            },
        };
    }

    emit(event, args = []) {
        if (this.eventCallbacks[event])
            return this.eventCallbacks[event].map(ele => ele(...args));
        
        return [];
    }
}