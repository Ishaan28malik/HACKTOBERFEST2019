const express = require('express');
const rateLimit = require('express-rate-limit');

const app = express();
const port = 3000;

// Define rate limit rule
const limiter = rateLimit({
    windowMs: 1 * 60 * 1000, // 1 minute window
    max: 5, // limit each IP to 5 requests per windowMs
    message: 'Rate limit exceeded',
});

// Apply rate limit to all requests
app.use(limiter);

app.get('/', (req, res) => {
    res.json({ message: 'Hello, World!' });
});

app.get('/items/:itemId', (req, res) => {
    res.json({ itemId: req.params.itemId, message: 'Item fetched successfully' });
});

app.post('/reset', (req, res) => {
    // Reset rate limit by clearing stored rate limit info
    // This functionality isn't provided by express-rate-limit out-of-the-box,
    // but for the purpose of this example, we'll assume a simple reset route.

    // This would be more complex in a real-world scenario and depend on how the rate limit information is stored.
    res.json({ message: 'Rate limits reset' });
});

app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}/`);
});
